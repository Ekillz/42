INSERT into ft_table(login, date_de_creation, groupe) select nom, date_naissance, "other"  from fiche_personne where CHAR_LENGTH(nom) < 9 AND INSTR(nom, 'a') > 0 ORDER BY nom limit 10;
