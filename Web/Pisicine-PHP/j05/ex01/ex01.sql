CREATE table ft_table (id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, login VARCHAR(8) NOT NULL default 'toto', groupe ENUM('staff', 'student', 'other') NOT NULL, date_de_creation DATE NOT NULL);
