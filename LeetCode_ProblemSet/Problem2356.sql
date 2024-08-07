SELECT 
    DISTINCT T1.TEACHER_ID AS TEACHER_ID,
    (
        SELECT COUNT(DISTINCT T2.SUBJECT_ID)
        FROM TEACHER T2
        WHERE T1.TEACHER_ID = T2.TEACHER_ID
    ) AS CNT
FROM TEACHER T1;