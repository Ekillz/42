SELECT etage_salle as "etage", SUM(nbr_siege) as 'sieges' from salle  GROUP by etage_salle ORDER by nbr_siege;
