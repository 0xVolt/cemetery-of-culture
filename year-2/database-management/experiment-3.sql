create table CLIENT_MASTER1
(
CLIENTNO varchar(6) ,
NAME varchar(20) not null,
ADDRESS1 varchar(30),
ADDRESS2 varchar(30),
CITY varchar(15),
PINCODE int,
STATE varchar(15),
BALDUE decimal(10,2),
PRIMARY KEY(CLIENTNO,NAME),
constraint CLIENT_MASTER1 check( substr(CLIENTNO, 1,1) IN ('C', 'c') ) 
);
create table PRODUCT_MASTER1
 (PRODUCTNO varchar(6),
 DESCRIPTION varchar(15) not null,
 PROFITPERCENT decimal(4,2)not null,
 UNIT_MEASURE varchar(10) not null,
 QTYONHAND int not null,
 REODERL_VL int not null,
 SELLPRICE decimal(8,2) not null,
 COSTPRICE decimal(8,2) not null,
 PRIMARY KEY (PRODUCTNO),
constraint PRODUCT_MASTER1 check( substr(PRODUCTNO, 1,1) IN ('P', 'p') ) 
);
create table SALESMAN_MASTER1
 (
SALESMANNO varchar(6),
SALESMANNAME varchar(20) not null,
ADDRESS1 varchar(30) not null,
ADDRESS2 varchar(30),
CITY varchar(15),
PINCODE int,
STATE varchar(15),
SALAMT real not null,
TGTTOGET decimal not null,
YTDSALES double not null,
REMARKS varchar(60),
PRIMARY KEY (SALESMANNO),
constraint sn check( substr(SALESMANNO, 1,1) IN ('S', 's') ),
constraint samt check(SALAMT!=0),
constraint tt check(TGTTOGET!=0) 
);

insert into CLIENT_MASTER1
(
CLIENTNO,
NAME,
CITY ,
PINCODE ,
STATE ,
BALDUE
)
values
(
'C00001','Ivan Bayross','Mumbai',400054,'Maharashtra',15000
),
(
'C00002','Mamta muzumdar','Madras',780001,'Tamil Nadu',0
),
(
'C00003','Chaya bankar','Mumbai',400057,'Maharastra',5000
),
(
'C00004','Ashwini Joshi','Banglore',560001,'Karnataka',0
),
(
'C00005','Hansel Colaco','Mumbai',400060,'Maharashtra',2000
);
insert into PRODUCT_MASTER1
(
PRODUCTNO,
DESCRIPTION ,
PROFITPERCENT ,
UNIT_MEASURE ,
QTYONHAND,
REODERL_VL, 
SELLPRICE,
COSTPRICE
)
values
(
'P00001','T-Shirt',5,'Piece',200,50,350,250
),
(
'P0345','Shirts',6,	'Piece',150,50,500,350
),
(
'P06734','Cotton jeans',5,'Piece',100,20,600,450
),
(
'P07865','Jeans',5,'Piece',100,20,750,500
),
(
'P07868','Trousers',2,'Piece',150,50,850,550
),
(
'P07885','Pull Overs',2.5,'Piece',80,30,700,450
),
(
'P07965','Denim jeans','4','Piece',100,40,350,250
),
(
'P07975','Lycra tops',5,'Piece',70,30,300,175
),
(
'P08865','Skirts',5,'Piece',75,	30,	450,300
);
insert into SALESMAN_MASTER1
(
SALESMANNO ,
SALESMANNAME ,
ADDRESS1 ,
ADDRESS2 ,
CITY ,
PINCODE ,
STATE  ,
SALAMT ,
TGTTOGET ,
YTDSALES 
)
values
(
'S00001','Aman','A/14','Worli','Mumbai',400002,'Maharashtra',1000,5000,250
),
(
'S00002','Omkar','65','Nariman','Mumbai',400001,'Maharashtra',3500,5000,350
),
(
'S00003','Raj','P-7','Bandra','Mumbai',400032,'Maharashtra',4000,5000,120
),
(
'S00004','Ashish','A/5','Juhu','Mumbai',400044,'Maharashtra',2000,5000,450
);

create table AUTHOR 
(Author_ID varchar(5), 
Lastname varchar(15) not null, 
Firstname varchar(15) not null, 
Email varchar(40), 
City varchar(15), 
Country varchar(15),
primary key (Author_ID)
);

create Table BOOK
(Book_ID varchar(5), 
Book_Title char(40) not null, 
Copies int ,
primary key (Book_ID),
constraint bi check(substr(Book_ID,1,1) IN ('b','B')),
constraint cp check (Copies>2)
); 

create table AUTHOR_LIST
(Author_ID varchar(5) , 
Book_ID varchar(5), 
Role varchar(5),
foreign key (Author_ID) references AUTHOR(Author_ID)
);

insert into AUTHOR
(
Author_ID , Lastname, Firstname, Email, City, Country
)
values
('02001','Tagore','Rabindranath','rtagore@gmail.com','Kolkata','India'),
('01001','Shakespear','William','william@gmail.com','Stratfod','United Kingdom'),
('01002','Rowling','J.K.','jkrowling@gmail.com','Yate','United Kingdom'),
('02002','Tharoor','Shashi','stharoor@gmail.com','London','United Kingdom');
insert into BOOK
(
Book_ID, Book_Title, Copies
)
values
('B1234','Gitanjali','100000'),
('B2569','The Tempest','45000'),
('B3590','Harry Potter','99000'),
('B9510','India','26000');
insert into AUTHOR_LIST
(
Author_ID , Book_ID , Role
)
values
('02001','01234','AUTH'),
('01001','22569','AUTH'),
('01002','33590','AUTH'),
('02002','89510','AUTH');

alter table AUTHOR_LIST 
add Publisher varchar(30);