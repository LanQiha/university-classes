<?php 
$message = "";

// recupération de la liste des tables
$stats = get_statistiques();

if($stats == null || count($stats) == 0) {
	$message .= "Aucune statistique n'est disponible!";
}else{

	// TODO


}
?>
