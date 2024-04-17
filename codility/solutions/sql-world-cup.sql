-- teams (team_id, team_name)
-- matches(match_id, host_team, guest_team, host_goals, guest_goals)

SELECT
    T.team_id AS team_id, T.team_name AS team_name, COALESCE(S.num_points, 0) AS num_points
FROM
    teams AS T LEFT JOIN (
        SELECT RESULT.team_id, SUM(score) AS num_points
        FROM
        (
            SELECT T.team_id AS team_id, (COUNT(T.team_name) * 3) AS score
            FROM teams AS T INNER JOIN matches AS M
                ON T.team_id = M.host_team OR T.team_id = M.guest_team
            WHERE (T.team_id = M.host_team AND M.host_goals > M.guest_goals)
                OR (T.team_id = M.guest_team AND M.guest_goals > M.host_goals)
            GROUP BY T.team_id
            UNION ALL
            SELECT T.team_id AS team_id, (COUNT(T.team_name) * 1) AS score
            FROM
                teams AS T INNER JOIN matches AS M
                    ON T.team_id = M.host_team OR T.team_id = M.guest_team
            WHERE M.host_goals = M.guest_goals
            GROUP BY T.team_id
        ) AS RESULT
        GROUP BY RESULT.team_id
    ) AS S
    ON T.team_id = S.team_id
ORDER BY num_points DESC, team_id ASC
