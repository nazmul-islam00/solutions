/* Write your PL/SQL query statement below */
SELECT 
    TO_CHAR(TO_DATE(T1.TRANS_DATE), 'YYYY-MM') AS month, 
    T1.COUNTRY AS country,
    COUNT(*) AS trans_count,
    NVL((
        SELECT COUNT(*) 
        FROM TRANSACTIONS T2
        WHERE 
            TO_CHAR(TO_DATE(T2.TRANS_DATE), 'YYYY-MM') = TO_CHAR(TO_DATE(T1.TRANS_DATE), 'YYYY-MM') AND
            (
                T2.COUNTRY = T1.COUNTRY OR
                (
                    T2.COUNTRY IS NULL AND
                    T1.COUNTRY IS NULL
                )
            ) AND
            T2.STATE = 'approved'
    ), 0) AS approved_count,
    SUM(T1.AMOUNT) AS trans_total_amount,
    NVL((
        SELECT SUM(T2.AMOUNT) 
        FROM TRANSACTIONS T2
        WHERE 
            TO_CHAR(TO_DATE(T2.TRANS_DATE), 'YYYY-MM') = TO_CHAR(TO_DATE(T1.TRANS_DATE), 'YYYY-MM') AND
            (
                T2.COUNTRY = T1.COUNTRY OR
                (
                    T2.COUNTRY IS NULL AND
                    T1.COUNTRY IS NULL
                )
            ) AND
            T2.STATE = 'approved'
    ), 0) AS approved_total_amount
FROM TRANSACTIONS T1
GROUP BY 
    TO_CHAR(TO_DATE(T1.TRANS_DATE), 'YYYY-MM'), 
    T1.COUNTRY
ORDER BY 
    month ASC,
    country DESC;