<!doctype html>
<!-- sujet1.php -->
<html>
	<head>
		<meta charset="utf-8" />
		<title>  </title>
		<style type="text/css"> 
		/* Déclarez les styles ici */
		
		.div1
		{
			background-color: orange;
			color: white;
			width: 80%;
			border-radius: 30px;
			font-size: 20px;
		}
		
		.div2
		{
			background-color: lightblue;
			color: white;
			border-radius: 30px;
			width: 80%;
		    font-size: 20px;
		    padding-top: 5px;
		    padding-bottom: 15px;
		}
		
		.div3
		{
			background-color: lightblue;
			border-radius: 30px;
			width: 80%;
			font-size: 15px;
			padding-top : 10px; 
			padding-bottom: 10px;
		}
		
		.div4
		{
			border-style: solid;
			padding-top: 5px;
			padding-bottom: 5px;
			width: 80%;
			border-radius: 20px;
			text-align: left;
			padding-left: 15px;
		}
		
		.color
		{
			color: green;
		}
		
		.color2
		{
			color: red;
		}
			
		   
		</style>
	</head>
	
	<?php 
	/* Écrivez ici les fonctions php */
	
	function nb_valide($nb)
	{
		if($nb < 0 or $nb > 255)
		{
			return false; 
		}
		return true; 
	}
	
	function ip_valide($ip)
	{
		$tab = explode(".", $ip);
		
		if(sizeof($tab) != 4)
		{
			return false;
		}
		
		for($i=0; $i<3; $i++)
		{
			if(nb_valide($tab[$i]) == false)
			{
				return false;
			}
		}
		return true;	
	}
	
	?>
            
	<body>
		<center>
			
		<div class="div1" name="titre">
			TP noté : sujet 1 <br/>
		</div>	
		
		<br/>
		
		<div class="div2" name="saisie">
		Entrez une adresse IPv4 en notation décimale pointée : <br/>
		
		<form name="adress" method="GET" action="sujet1.php">
			
			<input type="text" name="ip" value="1.1.1.1" size="30" maxlength="20" /> <br/>
			
			<input type="submit" value="Vérifier" name="action" />
		
		</form>
		
		</div>
		
		<br/>
		
		<div name="resultat" class="div3">
			<p class="color">
			<?php
			
			if(ip_valide($_GET['ip']) == true)
			{
				echo $_GET['ip'] . " est valide ! ";
			}
			
			?>
			</p>
			
			<p class="color2">
			
			<?php 
			
			if(ip_valide($_GET['ip']) == false)
			{
				echo $_GET['ip'] . " n'est pas valide. ";
			}
			
			?>
			
			</p>
			
		</div>
		
		<br/>
		
		 <div name="champs" class="div4">
			 
		 Voici ce qui à été transmis au server par le formulaire : <br/>
		 
		 <?php
		 
		 foreach($_GET as $k => $v)
		 {
			 echo "$k = $v <br/>";
		 }
		 
		 ?>
		 
		 </div>
		 
		 </center>
	
	</body>
</html>	
