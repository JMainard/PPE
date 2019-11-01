-- Creation base de donnée ProjetPPE/NewWorld  3.0 avec la table mixe de utilisateur et une meilleure optimisation 
-- Créer le 10/10/2019 par Jérémy Mainard

-- Supression des tables déjà existantes
drop table if exists horaire;
drop table if exists pr_Client;
drop table if exists jour;
drop table if exists commande;
drop table if exists panier;
drop table if exists annonceVente;
drop table if exists uniteMesure;
drop table if exists pointRelais;
drop table if exists client;
drop table if exists administrateur;
drop table if exists producteur;
drop table if exists utilisateur;
drop table if exists role;
drop table if exists mail;

-- Création des tables
create table horaire (
	prId int,
	jourId tinyint,
	horaireOuvertureMatin time,
	horaireFermetureMatin time,
	horaireOuvertureAM time,
	horaireFermetureAM time,
	primary key(prId,jourId)
	)engine=innodb charset=utf8;

create table pr_Client (
	prId int,
	clId int,
	distance float,
	primary key(prId,clId)
	) engine=innodb charset=utf8;
create table jour (
	jourId tinyint primary key,
	jourLib varchar(8)
	) engine=innodb charset=utf8;

create table commande (
	commId int,
	clId int,
	prId int,
	commDate date,
	commPrix varchar (20),
	commTypePaiement varchar(25),
	commDatePaiement date,
	primary key(commId,clId,prId)
	)engine=innodb charset=utf8;

create table producteur (
	prodId int primary key,
	prodGenre varchar(8),
	prodNomEntreprise varchar(50),
	prodNumSiret varchar(14),
	prodNumFixe varchar(14),
	prodNumMobile varchar(14),	
	userId int
	)engine=innodb charset=utf8;

create table panier (
	annId int,
	clId int,
	quantite float,
	primary key (annId,clId)
	)engine=innodb charset=utf8;

create table annonceVente (
	annId int,
	annUMesure smallint,
	prodId int,
	annProduit varchar(50),
	annVariete varchar(50),
	annCategorie varchar(50), -- Defini si c'est un fruit ou un légume
	annQuantite float,
	annPhoto text,
	annPrixKG float,
	annPrixHT float,
	annPrixTTC float,
	annDLC date,
	annValide bool, -- Sert a savoir si l'annonce a été ou non validé par un administrateur
	annSupprime bool,-- Ne supprime pas l'annonce la cache juste comme tout les bool suppprime
	primary key (annId,annUMesure)
	)engine=innodb charset=utf8;

create table uniteMesure (
	uMesureId smallint primary key,
	uMesureLib varchar (25)
	) engine=innodb charset=utf8;

create table pointRelais (
	prId int primary key,
	prNomEntreprise varchar(50),
	prTypeMagasin varchar (50),
	userId int
 	) engine=innodb charset=utf8;

create table client (
	clId int primary key,
	userId int
	)engine=innodb charset=utf8;

create table administrateur ( -- Tables  administrateur pour le backoffice 
	adminId int primary key,
	userId int
	) engine=innodb charset=utf8;


create table utilisateur (
	userId int primary key,
	userRole tinyint,
	userNom varchar(30),
	userPrenom varchar(30),
	userVille varchar(40),
	userCP varchar(5),
	userRue varchar(45),
	userLogin varchar (30),
	userMdp varchar(150),
	userMail varchar(40),
	userCleVerifMail varchar(255),
	userMailVerif bool,
	userSupprime bool
	)engine=innodb charset=utf8;


create table role (
	roleId tinyint primary key,
	roleLib varchar(40),
	roleDroit varchar(40),
	roleSupprime bool
	)engine=innodb charset=utf8;

create table mail (
	mailId int primary key auto_increment,
	mailAdresseProducteur varchar(80),
	mailObjet varchar(30),
	mailTexte text
)engine=innodb charset=utf8;

alter table pr_Client add constraint fk_ibfk_PointRelaisClient foreign key (prId) references pointRelais(prId),
					  add constraint fk_ibfk_ClientPr foreign key (clId) references client(clId);

alter table commande add constraint fk_ibfk_PointRelaisCommande foreign key (prId) references pointRelais(prId),
					 add constraint fk_ibfk_ClientCommande foreign key (clId) references client(clId);

alter table horaire add constraint fk_ibfk_PointRelaisHoraire foreign key (prId) references pointRelais(prId),
					add constraint fk_ibfk_Jour foreign key (jourId) references jour(jourId);


alter table panier add constraint fk_ibfk_ClientPanier foreign key (clId) references client(clId),
				   add constraint fk_ibfk_AnnonceVente foreign key (annId) references annonceVente(annId);

alter table annonceVente add constraint fk_ibfk_UniteMesure foreign key (annUMesure) references uniteMesure(uMesureId),
						 add constraint fk_ibfk_prodAnnonce foreign key (prodId) references producteur(prodId);

alter table utilisateur add constraint fk_ibfk_Utilisateur foreign key (userRole) references role(roleId);

alter table producteur add constraint fk_ibfk_Producteur foreign key (userId) references utilisateur (userId);

alter table pointRelais add constraint fk_ibfk_PointRelais foreign key (userId) references utilisateur (userId);

alter table client add constraint fk_ibfk_Clientid foreign key (userId) references utilisateur (userId);

alter table administrateur add constraint fk_ibfk_admin foreign key (userId) references utilisateur (userId);
