CREATE TABLE products
(
  prod_id CHAR(10) NOT NULL,
  vend_id CHAR(10) NOT NULL,
  prod_name CHAR(10) NOT NULL,
  prod_price DECIMAL(8,2) NOT NULL,
  prod_desc VARCHAR(1000) NULL
  );
  INSERT INTO products (prod_id, vend_id, prod_name, prod_price, prod_desc) VALUE ('10', '702', 'Jat', 32, 'Nift');
  INSERT INTO products (prod_id, vend_id, prod_name, prod_price, prod_desc) VALUE ('101', '702', 'Fork', 31.1, 'Sys');
  
DROP TABLE IF EXITS big_data;

DROP PROCEDURE IF EXISTS prc_gen_user;
CREATE TABLE 'big_data' (
  'uid' int(11) NOT NULL AUTO_INCREMENT,
  'mobil' char(11) DEFAULT NULL,
  'passwd' varchar(50) DEFAULT NULL,
  'name' varchar(50) DEFAULT NULL,
  'sex' tinyint DEFAULT NULL,
  'birthday' datetime DEFAULT NULL,
  'update_time' datetime DEFAULT NULL,
  PRIMARY KEY ('uid')
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
  
  CREATE PROCEDURE prc_gen_user(l_cnt int)
  BEGIN
    DECLARE x INT DEFAULT 0;
    DECLARE p char(11);
    WHILE x < l_cnt
    DO
      SET x = x + 1;
      SET p = concat('1', substring(cast(3 + (rand() * 10) % 7 AS char(50)), 1,1), right(left(trim(cast(rand() AS char(50))),11),9));
      INSERT INTO big_data(mobil,passwd,name, sex, birthday, update_time) VALUE(p, 
                                                                                md5(ceiling(rand() * 1000000)),
                                                                                concat(substring())
                                                                                