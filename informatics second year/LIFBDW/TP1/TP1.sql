/* Question 1  AS */
SELECT titre AS titre_film
FROM Film
ORDER BY titre_film ASC;

/* Question 2 ORDER BY*/
SELECT nom, prenom, annee_nais
FROM Artiste
WHERE nom = 'Scott'
ORDER BY prenom ASC;

/* Question 3 DISTINCT */
SELECT DISTINCT annee
FROM Film
ORDER BY annee DESC;

/* Question 4 LIMIT */
SELECT annee
FROM Film
ORDER BY annee ASC
LIMIT 3;

/* Question 5 */
SELECT annee, titre
FROM Film
WHERE annee >= 1990

INTERSECT

SELECT annee, titre
FROM Film
WHERE annee <= 2021
ORDER BY annee DESC, titre ASC;

/* Question 6 */

SELECT *
FROM Film
WHERE titre LIKE 'T%'

UNION

SELECT *
FROM Film
WHERE SUBSTRING(titre, 2, 1) = 'o'
ORDER BY LENGTH(titre) ASC;

/* Question 7 */
SELECT titre, annee 
FROM Film 
WHERE titre LIKE '% % %' 

INTERSECT 

SELECT titre, annee 
FROM Film 
WHERE id_realisateur IS NOT NULL;

/* Question 8 */
SELECT nom
FROM Artiste
WHERE annee_nais IS NULL;

/* Question 9 */
SELECT f.titre, f.annee, a.nom, a.prenom
FROM Film f JOIN Artiste a ON f.id_realisateur = a.ida
WHERE f.annee > 1990
ORDER BY f.annee DESC, f.titre ASC, a.nom ASC, a.prenom ASC;

/* Question 10 */
SELECT f.titre, f.annee
FROM Film f JOIN Artiste a ON f.id_realisateur = a.ida
WHERE UPPER(a.nom) = UPPER('Woo') AND a.prenom = 'John'
ORDER BY annee ASC;

/* Question 11 */
SELECT f.annee, f.titre, a.nom, a.prenom
FROM Film f JOIN Artiste a ON f.id_realisateur = a.ida
ORDER BY f.annee DESC, f.titre, a.nom, a.prenom;

/* SELECT f.titre, f.annee, 
       IFNULL(a.nom, 'NULL') AS nom,
       IFNULL(a.prenom, 'NULL') AS prenom
FROM Film f 
LEFT JOIN Artiste a ON f.id_realisateur = a.ida
ORDER BY f.annee DESC, f.titre ASC, nom ASC, prenom ASC; */

/* Question 12 */
SELECT titre, annee 
FROM Film f1 
WHERE f1.annee > (SELECT annee 
                FROM Film f2 
                WHERE f2.titre = 'Pulp Fiction');

/* Question 13 */
SELECT DISTINCT nom AS nom_real, prenom AS prenom_real
FROM Artiste
ORDER BY nom_real ASC, prenom_real ASC;

/* Question 14 */
SELECT DISTINCT a1.nom, a2.nom
FROM Artiste a1 JOIN Artiste a2 ON a1.annee_nais = a2.annee_nais AND a1.nom != a2.nom AND a1.ida < a2.ida;

/* Question 15 */
SELECT DISTINCT a.nom, a.prenom
FROM Artiste a JOIN Film f ON a.ida = f.id_realisateur
WHERE (YEAR(CURDATE()) - f.annee) >= 30
ORDER BY a.nom ASC, a.prenom ASC;

SELECT DISTINCT a.nom, a.prenom
FROM Artiste a JOIN Film f ON a.ida = f.id_realisateur
WHERE (YEAR(CURDATE()) - f.annee) >= 30
ORDER BY f.titre ASC;

/* Question 16 */
SELECT f1.titre, f2.titre
FROM Film f1 JOIN Film f2 ON LOCATE(f2.titre, f1.titre) != 0 AND f2.titre != f1.titre;