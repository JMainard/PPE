<!-- Page de verification apres envoi mail -->
<?php
session_start();
include("connect.php");
	if($_GET['key']==md5($_SESSION['clef']) && $_GET['id']==$_SESSION['id'])
	{
$clef=$_SESSION['clef'];
$requete="update Producteur set mailVerif=1 where prodId=".$_SESSION['id']." and prodCleVerifMail='".$clef."'";

if ($maBase->query($requete))
{
echo "ok";
}
else
{
echo "non ";
echo $requete;
}
}

?>
<html>
	<head>
			<title> Deolia verification email </title>
			<meta charset="utf8" />
	</head>
	<body>

				<h1> Merci de votre confiance </h1>
			<p> Lors  de votre première connexion, vous pourrez compléter votre profil plus en detail pour commencer  vendre en remplissant vos coordonnée bancaire et toutes information relative à la vente securisé sur internet </p>
	</body>
</html>
