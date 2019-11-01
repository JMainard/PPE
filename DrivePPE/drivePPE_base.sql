-- Creation base de donnée sur le drivePPE producteur/point de vente /acheteur
-- Base créee le 10-05-2019 par J.Mainard

-- Suppression des tables deja existantes
drop table if exists Horaire;
drop table if exists pr_Client;
drop table if exists Prod_Client;
drop table if exists CQVLP;
drop table if exists Jour;
drop table if exists PointRelais;
drop table if exists Commande;
drop table if exists Client;
drop table if exists Producteur;
drop table if exists Produit;
drop table if exists Panier;
drop table if exists AnnonceVente;
drop table if exists UniteMesure;


-- Creation des tables
create table Horaire (
	prId int,
	jourId tinyint,
	horaireOuvertureMatin time,
	horaireFermetureMatin time,
	horaireOuvertureAM time,
	horaireFermetureAM time,
	primary key (prId,jourId)
	)engine=innodb charset=utf8;

create table pr_Client (
	prId int,
	clId int,
	ditance varchar(50),
	primary key(prId,clId)
	)engine=innodb charset=utf8;

create table Prod_Client (
	prodId int,
	clId int,
	distance varchar(50),
	primary key(prodId,clId)
	)engine=innodb charset=utf8;

create table CQVLP (
	prodId int,
	produitId int,
	primary key(prodId,produitId)
	)engine=innodb charset=utf8;

create table Jour (
	jourId tinyint primpary key,
	jourLib varchar(8)
	) engine=innodb charset=utf8;

create table PointRelais (
	prId int primary key ,
	prNomGerant varchar(25),
	prPrenomGerant varchar(25),
	prNomEntreprise varchar (50),
	prTypeMagasin varchar (50),
	prVille varchar (25),
	prCp varchar(5),
	prAdresse varchar (35),
	prEmail varchar(40),
	prLogin varchar(30),
	prMdp varchar(255),
	prCleVerifMail varchar(255),
	prMailVerif bool
	) engine=innodb charset=utf8;

create table Commande (
	commId int,
	clId int,
	prId int,
	commDate date,
	commPrix varchar (20),
	commTypePaiement varchar(25),
	commDatePaiement date,
	primary key(commId,cliId,prId)
	)engine=innodb charset=utf8;

create table Client (
	clId int primary key,
	clPrenom varchar(35),
	clNom varchar(35),
	clVille varchar (25),
	clCP varchar (5),
	clRue varchar (25),
	clMail varchar (40),
	clLogin varchar(40),
	clMdp varchar (255),
	clleVerifMail varchar(255),
	clMailVerif bool
	) engine=innodb charset=utf8;

create table Producteur (
	prodId int primary key,
	prodGenre varchar (8),
	prodPrenom varchar(25),
	prodNom varchar(25),
	prodNomEntreprise varchar (50),
	prodNumSiret varchar (14),
	prodNumFixe varchar (14),
	prodNumMobile varchar (14),
	prodVille varchar (25),
	prodCP varchar(5),
	prodAdresse varchar(30),
	prodEmail varchar(40),
	prodLogin varchar(30),
	prodMdp varchar(255),
	prodCleVerifMail varchar(255),
	mailVerif bool
	) engine=innodb charset=utf8;

create table Produit (
	produitId int primary key,
	prodLib varchar(30),
	prodDesc text
	)engine=innodb charset=ut8;

create table Panier (
	annId int,
	clId int,
	quantite tinyint,
	primary key (annId,clId)
	)engine=innodb charset=utf8;

create table AnnonceVente (
	annId int,
	annUMesure smallint,
	annLib varchar(30),
	annPhoto text,
	annMesure smallint,
	annPrixTTC float,
	annPrixHTC float,
	annPrixKG float,
	annDesc text,
	primary key (annId,annUMesure)
	)engine=innodb charset=utf8;

create tableUniteMesure (
	uMesureId smallint primary key,
	uMesureLib varchar (10)
	)engine=innodb charset=utf8;

alter table Prod_Client add constraint fk_ibfk_Prod foreign key(prodId) references Producteur (prodId),
				  add constraint fk_ibfk_Client foreign key(clId) references Client(clId);

alter table CQLVP add constraint fk_ibfk_Prod foreign key (prodId) references Producteur(prodId),
				  add constraint fk_ibfk_Produit foreign key (produitId) references Produit(produitId);

alter table pr_Client add constraint fk_ibfk_PointRelais foreign key (prId) references PointRelais(prId),
					  add constraint fk_ibfk_CLient foreign key (clId) references Client(clId);

alter table Commande add constraint fk_ibfk_PointRelais foreign key (prId) references PointRelais(prId),
					 add constraint fk_ibfk_Clientforeing key (clId) references Client(clId);

alter table Horaire add constraint fk_ibfk_PointRelais foreign key (prId) references PointRelais(prId);

alter table Jour add constraint fk_ibfk_Jour foreign key (jourId) references Horaire (jourId);

alter table Panier add constraint fk_ibfk_Client foreign key (clId) references Client(clId),
				   add constraint fk_ibfk_AnnonceVente foreign key (annId) references AnnonceVente(annId);

alter table AnnonceVente add constraint fk_ibfk_UniteMesure foreign key (annUMesure) references UniteMesure(uMesureId);

