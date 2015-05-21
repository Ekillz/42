SELECT nom, prenom from fiche_personne WHERE INSTR(nom, '-') > 0 OR INSTR(prenom, '-') > 0 ORDER BY nom, prenom;
