select titre, resum, duree_min from film where INSTR(resum, '42') > 0 OR INSTR(titre, '42') > 0 ORDER BY duree_min;
