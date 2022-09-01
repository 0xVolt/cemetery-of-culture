USE ADBMS_LAB;

CREATE TABLE CLIENT_MASTER (
	CLIENTNO varchar(6),
	NAME varchar(20),
	ADDRESS1 varchar(30),
	ADDRESS2 varchar(30), 
	CITY varchar(15),
	PINCODE int,
	STATE varchar(15),
	BALDUE decimal(10,2),
	PRIMARY KEY (NAME)
);

CREATE TABLE PRODUCT_MASTER (
	PRODUCTNO varchar(6),
	DESCRIPTION varchar(15),
	PROFITPERCENT decimal(4,2),
	UNIT_MEASURE varchar(10),
	QTYONHAND int,
	REODERL_VL int,
	SELLPRICE decimal(8,2),
	COSTPRICE decimal(8,2),
	PRIMARY KEY (DESCRIPTION)
);

CREATE TABLE SALESMAN_MASTER (
	SALESMANNO varchar(6),
	SALESMANNAME varchar(20),
	ADDRESS1 varchar(30),
	ADDRESS2 varchar(30),
	CITY varchar(15),
	PINCODE int,
	STATE varchar(15),
	SALAMT real,
	TGTTOGET decimal(8, 2),
	YTDSALES float(25),
	REMARKS varchar(60),
	PRIMARY KEY (SALESMANNAME)
);

INSERT INTO CLIENT_MASTER (
	CLIENTNO, NAME, CITY, PINCODE, STATE, BALDUE
)
VALUES 
	('C00001','Ivan Bayross','Mumbai',400054,'Maharashtra',15000), 
	('C00002','Mamta muzumdar','Madras',780001,'Tamil Nadu',0), 
	('C00003','Chaya bankar','Mumbai',400057,'Maharastra',5000), 
	('C00004','Ashwini Joshi','Banglore',560001,'Karnataka',0), 
	('C00005','Hansel Colaco','Mumbai',400060,'Maharashtra',2000), 
	('C00006','Deepak sharma','Manglore',560050,'Karnataka',0)
;

INSERT INTO PRODUCT_MASTER (
	PRODUCTNO, DESCRIPTION, PROFITPERCENT, UNIT_MEASURE, QTYONHAND, REODERL_VL, SELLPRICE, COSTPRICE
) 
VALUES
	('P00001','T-Shirt',5,'Piece',200,50,350,250), 
	('P0345','Shirts',6,'Piece',150,50,500,350), 
	('P06734','Cotton jeans',5,'Piece',100,20,600,450), 
	('P07865','Jeans',5,'Piece',100,20,750,500), 
	('P07868','Trousers',2,'Piece',150,50,850,550), 
	('P07885','Pull Overs',2.5,'Piece',80,30,700,450), 
	('P07965','Denim jeans','4','Piece',100,40,350,250), 
	('P07975','Lycra tops',5,'Piece',70,30,300,175), 
	('P08865','Skirts',5,'Piece',75,30,450,300)
;

INSERT INTO SALESMAN_MASTER (
	SALESMANNO, SALESMANNAME, ADDRESS1, ADDRESS2, CITY, PINCODE, STATE
) 
VALUES
	('S00001','Aman','A/14','Worli','Mumbai',400002,'Maharashtra'),
	('S00002','Omkar','65','Nariman','Mumbai',400001,'Maharashtra'),
	('S00003','Raj','P-7','Bandra','Mumbai',400032,'Maharashtra'),
	('S00004','Ashish','A/5','Juhu','Mumbai',400044,'Maharashtra')
;


select NAME from CLIENT_MASTER;

select * from CLIENT_MASTER;

select NAME,CITY,STATE from CLIENT_MASTER;

select DESCRIPTION from PRODUCT_MASTER;

select NAME from CLIENT_MASTER where CITY='Mumbai';

update CLIENT_MASTER set CITY = 'Banglore' where CLIENTNO ='C00005';
select * from CLIENT_MASTER where CLIENTNO = 'C00005';

update CLIENT_MASTER set BALDUE=1000 where CLIENTNO='C00001';

select * from CLIENT_MASTER where CLIENTNO='C00001';

update PRODUCT_MASTER set COSTPRICE=950 where DESCRIPTION ='Trousers' ;

update SALESMAN_MASTER set CITY='Pune';

delete from PRODUCT_MASTER where QTYONHAND = 100;

delete from CLIENT_MASTER where STATE = 'Tamil Nadu';

alter table CLIENT_MASTER add Telephone int;

alter table PRODUCT_MASTER modify SELLPRICE decimal(10,2);

drop table CLIENT_MASTER;
drop table product_master;
drop table salesman_master;

alter table SALESMAN_MASTER rename to sman_mast;

SELECT * FROM CLIENT_MASTER;
SELECT * FROM PRODUCT_MASTER;
SELECT * FROM SALESMAN_MASTER;
