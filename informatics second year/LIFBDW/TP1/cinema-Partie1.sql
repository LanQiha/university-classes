-- -----------------------------------------
-- Nicolas Lumineau
-- -----------------------------------------
-- Données TPs BDW 2024
-- -----------------------------------------


-- BLOC 1 : Création de la table Artiste

CREATE TABLE Artiste  (ida INTEGER,
		       nom VARCHAR (20),
               prenom VARCHAR (15),
		       annee_nais SMALLINT ,
		       PRIMARY KEY (ida));

-- BLOC 2 : Création des n-uplets pour peupler la table Artiste

INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (1, 'Allen', 'Woody', 1938);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (2, 'Lynch', 'David', 1946);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (3, 'Kusturica', 'Emir', 1959);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (4, 'Lang', 'Fritz', 1899);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (5, 'Eastwood', 'Clint', 1932);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (6, 'Hitchcock', 'Alfred', 1898);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (7, 'Kubrick', 'Stanley', 1935);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (8, 'Curtis', 'Michael', 1902);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (9, 'Stewart', 'James', 1911);
INSERT INTO Artiste (ida, nom, prenom)
            VALUES  (10,'Novak', 'Kim');
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (11, 'Hunt', 'Greg', 1950);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (12, 'Tarantino', 'Quentin', 1948);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (13, 'Willis', 'Bruce', 1952);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (14, 'Spielberg', 'Steven', 1943);
INSERT INTO Artiste (ida, nom, prenom)
            VALUES  (15, 'Hudson', 'Hugh');
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (16, 'Gillian', 'Terry', 1944);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (17, 'Truffaut', 'Francois', 1938);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (18, 'Lambert', 'Christophe', 1953);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (19, 'Keitel', 'Harvey', 1940);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (20, 'Woo', 'John', 1951);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (21, 'Travolta', 'John', 1953);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (22, 'Cage', 'Nicolas', 1954);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (23, 'DiCaprio', 'Leonardo', 1973);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (24, 'Cameron', 'James', 1943);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (25, 'Cruise', 'Tom', 1960);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (26, 'De Palma', 'Brian', 1953);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (27, 'Depp', 'Johnny', 1967);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (28, 'Ricci', 'Christina', 1974);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (29, 'Burton', 'Tim', 1958);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES  (30, 'Bergman', 'Ingrid', 1915);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES (31, 'Shyamalan' , 'M. Night', 1970);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES (32, 'Villeneuve' , 'Denis', 1967);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES (33, 'Coleman','Zendaya', 1996);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
            VALUES (34, 'MacLachlan','Kyle', 1959);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
	    VALUES( 35, 'Kosinski', 'Joseph', 1974);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
	    VALUES( 36, 'Scott', 'Tony', 1944);
INSERT INTO Artiste (ida, nom, prenom, annee_nais)
	    VALUES( 37, 'Scott', 'Ridley', 1937);
	     	


-- BLOC 3 : Création de la table Film

CREATE TABLE Film  (idf INTEGER,
                    titre    VARCHAR (30),
                    annee   SMALLINT,
                    id_realisateur INTEGER,
	            PRIMARY KEY (idf),
	            FOREIGN KEY (id_realisateur) REFERENCES Artiste(ida));


-- BLOC 4 : Création des n-uplets pour peupler la table Film

INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (10, 'Annie Hall', 1977, 1);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (57, 'Brazil', 1984, 16);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (5, 'Underground', 1995, 3);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (38, 'Metropolis', 1926, 4);
INSERT INTO Film (idf, titre, annee, id_realisateur)		
		VALUES (45, 'Impitoyable', 1992, 5);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (65, 'Vertigo', 1958, 6);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (7, 'Shining', 1980, null);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (6, 'Psychose', 1960, 6);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (3, 'Twin Peaks', 1990, 2);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (90, 'Casablanca', 1942, 8);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (85, 'Greystocke', 1984, 15);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (89, 'Le dernier metro', 1980, 17);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (1, 'Reservoir Dogs', 1992, 12);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (43, 'Manhattan', 1979, 1);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (11, 'Jurassic Park', 1992, 14);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (32, 'Rencontres du 3eme type', 1978, 14);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (33, 'Piège de cristal', 1990, 11);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (34, 'Une journée en enfer', 1994, 11);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (35, '48 minutes pour vivre', 1992, 11);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (73, 'Pulp Fiction', 1995, 12);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (75, 'Top Gun', 1986, 36);		
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (101, 'Broken Arrow', 1996, 20);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (102, 'Volte-Face', 1997, 20);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (104, 'Titanic', 1998, 24);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (135, 'Mission Impossible 2', 2000, 20);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (136, 'Mission Impossible', 1997, 26);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (142, 'Edward aux mains d''argent', 1990, 29);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (141, 'Sleepy Hollow', 1999, 29);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (160, 'Sixième sens', 2000, 31);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (161, 'Dune', 2021, 32);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (162, 'Dune', 1984, 2);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (231, 'Top Gun : Maverick', 2022, 35);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (181, 'Alien, le huitième passager', 1979, 36);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (182, 'Blade Runner', 1982, 36);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (183, '1492, Christophe Colomb', 1992, null);
INSERT INTO Film (idf, titre, annee, id_realisateur)
		VALUES (184, 'Alien: Covenant', 2017, 36);