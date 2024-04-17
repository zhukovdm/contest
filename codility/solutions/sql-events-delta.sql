SELECT FST.event_type AS event_type, (FST.value - SND.value) AS value FROM
(
    SELECT * FROM events AS A
        WHERE NOT EXISTS (
            SELECT * FROM events AS B WHERE A.event_type = B.event_type AND A.time < B.time)
) AS FST
INNER JOIN
(
    SELECT * FROM events AS A
        WHERE 1 = (
            SELECT COUNT(*) FROM events AS B WHERE A.event_type = B.event_type AND A.time < B.time)
) AS SND
ON FST.event_type = SND.event_type
ORDER BY FST.event_type
