WITH 
    FIRST_ORDER_IDS AS (
        SELECT 
            DISTINCT(D1.CUSTOMER_ID),
            (
                SELECT D2.DELIVERY_ID AS DELIVERY_ID
                    FROM DELIVERY D2
                    WHERE 
                        D2.CUSTOMER_ID = D1.CUSTOMER_ID AND 
                        D2.ORDER_DATE = (
                            SELECT MIN(D3.ORDER_DATE)
                            FROM DELIVERY D3
                            WHERE D3.CUSTOMER_ID = D1.CUSTOMER_ID
                        )
            ) AS DELIVERY_ID
        FROM DELIVERY D1
    ),

    FIRST_ORDER_DELIVERY AS (
        SELECT
            D.ORDER_DATE AS ORDER_DATE,
            D.CUSTOMER_PREF_DELIVERY_DATE AS DELIVERY_DATE
        FROM 
            FIRST_ORDER_IDS F JOIN
            DELIVERY D
        ON F.DELIVERY_ID = D.DELIVERY_ID
    ),

    FIRST_ORDER_IMMEDIATE_DELIVERY AS (
        SELECT *
        FROM FIRST_ORDER_DELIVERY F
        WHERE F.ORDER_DATE = F.DELIVERY_DATE
    )

SELECT
    ROUND(
        (SELECT COUNT(*) 
        FROM FIRST_ORDER_IMMEDIATE_DELIVERY) /
        (SELECT COUNT(*)
        FROM FIRST_ORDER_IDS)
    , 4) * 100 AS immediate_percentage
FROM DUAL;