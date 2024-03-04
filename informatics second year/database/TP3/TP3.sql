SELECT COUNT(*) as nb_cinéma
FROM Cinema;

SELECT a.nom, a.prenom, COUNT(*) as nb_films
FROM Film f JOIN artiste a ON a.ida = f.id_realisateur
GROUP BY a.nom, a.prenom
ORDER BY nb_films DESC, a.nom ASC;

SELECT c.nom, c.ville, SUM(s.capacite) as nb_total_sieges
FROM Cinema c JOIN Salle s ON s.idc = c.idc
GROUP BY c.nom, c.ville
ORDER BY nb_total_sieges DESC, c.nom ASC;

SELECT c.nom, c.ville, ROUND(AVG(s.capacite), 2) as nb_moy_sieges
FROM Cinema c JOIN Salle s ON s.idc = c.idc 
GROUP BY c.nom, c.ville
ORDER BY nb_moy_sieges DESC, c.nom ASC;

SELECT c.nom, c.ville, MAX(s.capacite) as nb_max_sieges
FROM Cinema c JOIN Salle s ON s.idc = c.idc 
GROUP BY c.nom, c.ville
ORDER BY nb_max_sieges DESC, c.nom ASC;

SELECT c.nom, c.ville
FROM Cinema c JOIN Salle s ON s.idc = c.idc
WHERE s.est_climatise = 'O'
GROUP BY c.nom, c.ville
HAVING COUNT(s.idc) >= 2;

SELECT c.*
FROM Cinema c 
JOIN Salle s ON s.idc = c.idc 
WHERE s.est_climatise = 'N' 
AND s.capacite = (
    SELECT MAX(capacite) 
    FROM Salle 
    WHERE est_climatise = 'N'
);

SELECT c.nom, COUNT(DISTINCT f.idf) as nb_diff_films
FROM Cinema c JOIN Salle s ON s.idc = c.idc
              JOIN Seance se ON se.idc = s.idc
              JOIN Film f ON f.idf = se.idf
GROUP BY c.nom
HAVING COUNT(DISTINCT f.idf) > 5
ORDER BY c.nom ASC;