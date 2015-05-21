SELECT nom, prenom, LEFT(date_naissance , 10) AS 'date de naissance' FROM fiche_personne where LEFT(date_naissance, 4) = 1989 ORDER BY nom;
