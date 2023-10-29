<?php

require_once '../../LIB/librairie-res.php'; 

global $auteur;

function retourne_auteur()
{
	global $auteur;
	
	$tab = explode("/", $_SERVER['REQUEST_URI']);
	return $tab[1];
}

function ajout_post_msg()
{
	global $auteur;
	
	$nbPost = prendre_un_post();
	
	fopen($nbPost.'-msg.txt', 'w');
	
	$ligne = "------------------------------";
	
	file_put_contents($nbPost.'-msg.txt', $ligne, FILE_APPEND|LOCK_EX);
	file_put_contents($nbPost.'-msg.txt', "\nmessage\n", FILE_APPEND|LOCK_EX);
	file_put_contents($nbPost.'-msg.txt', $auteur."\n", FILE_APPEND|LOCK_EX);
	file_put_contents($nbPost.'-msg.txt', date("Y-m-d H:i:s")."\n", FILE_APPEND|LOCK_EX);
	file_put_contents($nbPost.'-msg.txt', "0\n", FILE_APPEND|LOCK_EX);
	file_put_contents($nbPost.'-msg.txt', "\n", FILE_APPEND|LOCK_EX);
	file_put_contents($nbPost.'-msg.txt', $_POST["post_msg"]."\n", FILE_APPEND|LOCK_EX);
	file_put_contents($nbPost.'-msg.txt', $ligne."\n", FILE_APPEND|LOCK_EX);
}

function  affiche_post($fichier)
{
	$tab = file($fichier);
	return $tab;
}

function ajout_post_com()
{
	
}

?>
