<?php
/* connexion a la base de données */
	$serveur="localhost";
	$baseName="drive";
	$mdp="elini01";
	$user="jmainard";
	$maBase=new mysqli($serveur,$user,$mdp,$baseName);
	if($maBase->connect_errno)
		echo"Erreur: ".$maBase->connect_error;
/*	else
		echo $maBase->host_info;
*/
?>



