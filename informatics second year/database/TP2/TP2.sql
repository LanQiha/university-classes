/* 1. Nom et prénom des acteurs/actrices. Le résultat sera affiché selon l’ordre lexicographique 
sur le nom, puis sur le prénom.
a. version SANS sous-requête
b. version AVEC sous-requête non corrélée 
c. version AVEC sous-requête corrélée */

/* On évite les sous-requêtes corrélées */

SELECT DISTINCT a.nom, a.prenom
FROM artiste a JOIN Joue j ON a.ida = j.ida
ORDER BY nom ASC, prenom ASC;

SELECT DISTINCT a.nom, a.prenom 
FROM artiste a 
WHERE ida IN (
    SELECT ida
    FROM Joue
    )
ORDER BY nom ASC, prenom ASC;

SELECT a.nom, a.prenom 
FROM artiste a
WHERE EXISTS (
    SELECT * 
    FROM Joue j
    WHERE a.ida = j.ida
)
ORDER BY a.nom ASC, a.prenom ASC;

/* 2. Les films projetés au moins une fois dans une salle de capacité supérieure ou égale à 100 places 
dans un cinéma marseillais entre 1991 et 2015. Le résultat sera trié par année de sortie selon l'ordre 
chronologique.
a. version SANS sous-requête
b. version SANS jointure et AVEC des sous-requêtes */ /* PB CORRECTION */

SELECT DISTINCT f.*
FROM Film f JOIN Seance se ON f.idf = se.idf 
            JOIN Salle sa ON sa.num_salle = se.num_salle
            JOIN Cinema c ON c.idc = sa.idc
WHERE c.ville LIKE "Marseille%" AND sa.capacite >= 100 AND se.annee BETWEEN 1991 and 2015
ORDER BY f.annee ASC;

SELECT DISTINCT * 
from Film 
WHERE idf IN (
    SELECT idf
    FROM Seance 
    WHERE annee BETWEEN 1991 and 2015 AND idc IN (
        SELECT idc 
        FROM Cinema 
        WHERE ville LIKE "Marseille%" AND num_salle IN (
            SELECT num_salle
            FROM Salle
            WHERE capacite >= 100
        )
    )
)
ORDER BY annee ASC;

/* 3. Titre des films dont le réalisateur est né avant 1940 ou dont au moins une actrice joue le rôle de 'Chani'.
a. version avec doublons autorisés (Voir le résultat attendu)
b. version sans doublons (Voir le résultat attendu) */ /* PAS DE CORRECTION */

SELECT f.titre 
FROM Film f JOIN artiste a ON f.id_realisateur = a.ida 
WHERE a.annee_nais < 1940 

UNION /* PAS BESOIN DE DISTINCT */

SELECT f.titre 
FROM Film f JOIN artiste a ON f.id_realisateur = a.ida
            JOIN Joue j ON j.ida = a.ida
WHERE j.nom_role = "Chani";

SELECT f.titre 
FROM Film f JOIN artiste a ON f.id_realisateur = a.ida 
WHERE a.annee_nais < 1940 

UNION ALL /* AVEC LES DOUBLONS */ 

SELECT f.titre 
FROM Film f JOIN artiste a ON f.id_realisateur = a.ida
            JOIN Joue j ON j.ida = a.ida
WHERE j.nom_role = "Chani"
;

/* 4. L'identifiant et le nom des cinémas qui n'ont aucune salle climatisée.
a. version avec combinaison de requêtes
b. version avec sous-requête */ /* CORRECT */

SELECT c.idc, c.nom 
FROM Cinema c JOIN Salle s ON c.idc = s.idc

EXCEPT

SELECT c.idc, c.nom
FROM Cinema c JOIN Salle s ON c.idc = s.idc
WHERE est_climatise = 'O';

SELECT idc, nom 
FROM Cinema 
WHERE idc NOT IN (
    SELECT idc 
    FROM Salle
    WHERE est_climatise = 'O'
);

/* 5. Le nom des rôles qui apparaissent dans au moins deux films différents.
a. version sans sous-requête
b. version avec sous-requête corrélée */

SELECT j.nom_role 
FROM Joue j JOIN Film f ON j.idf = f.idf 
WHERE

SELECT nom_role 
FROM Joue 
WHERE idf IN (
    SELECT idf 
    FROM Film 
    WHERE 
)

/* 6. Le nom des rôles qui apparaissent dans exactement deux films différents.
a. version avec une combinaison de requêtes
b. version avec sous-requête */

SELECT j.nom_role 
FROM Joue j JOIN Film f ON j.idf = f.idf 
WHERE

SELECT nom_role 
FROM Joue 
WHERE idf IN (
    SELECT idf 
    FROM Film 
    WHERE 
) 

/* 7. Identifiant et titre des films projetés à la fois à Paris, Lyon et Marseille 
(quelque soit l'arrondissement). */ /* CORRECT */

SELECT f.idf, f.titre
FROM Film f JOIN Seance se ON f.idf = se.idf
            JOIN Cinema c ON c.idc = se.idc 
WHERE c.ville LIKE "Paris%"

INTERSECT

SELECT f.idf, f.titre
FROM Film f JOIN Seance se ON f.idf = se.idf
            JOIN Cinema c ON c.idc = se.idc
WHERE c.ville LIKE "Lyon%"

INTERSECT

SELECT f.idf, f.titre
FROM Film f JOIN Seance se ON f.idf = se.idf
            JOIN Cinema c ON c.idc = se.idc
WHERE c.ville LIKE "Marseille%";

/* 8. Nom et année de naissance de l’artiste le plus vieux de la base de données. 
a. version avec un ALL
b. version avec un EXISTS */

SELECT nom, annee_nais 
FROM artiste a
WHERE a.annee_nais IS NOT NULL AND NOT EXISTS (
    SELECT nom, annee_nais 
    FROM artiste r 
    WHERE r.annee_nais < a.annee_nais
    );

SELECT nom, annee_nais 
FROM artist a
