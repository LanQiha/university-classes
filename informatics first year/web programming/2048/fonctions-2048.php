<?php

global $score ;
$score = 0;

global $grille;
$grille = array_fill(0,4,array_fill(0,4,0));

/* --------------------
		
Affiche grille

--------------------- */

/*
for ($ligne=0; $ligne<4; $ligne++) 
{
for ($colonne=0; $colonne<4; $colonne++) 
{
echo $grille[$ligne][$colonne];
}
}

$nbElement = 1;
for ($ligne=0; $ligne<4; $ligne++) 
{
for ($colonne=0; $colonne<4; $colonne++) 
{
if ( ($nbElement % 4) != 0 )
{ 
$tbl[$ligne][$colonne]=0;
echo $tbl[$ligne][$colonne]; echo " ";
}

else 
{
	
$tbl[$ligne][$colonne]=0;
echo $tbl[$ligne][$colonne]; echo " ";
echo "<br/>";

}
$nbElement++;
}
}
*/

// affiche_sept_variables() [WORKS]

function affiche_sept_variables()
{
echo "HTTP_USER_AGENT="; echo $_SERVER['HTTP_USER_AGENT']; echo "<br />";
echo "HTTP_HOST="; echo $_SERVER['HTTP_HOST']; echo "<br />";
echo "DOCUMENT_ROOT="; echo $_SERVER['DOCUMENT_ROOT']; echo "<br />";
echo "SCRIPT_FILENAME="; echo $_SERVER['SCRIPT_FILENAME']; echo "<br />";
echo "PHP_SELF="; echo $_SERVER['PHP_SELF']; echo "<br />";
echo "REQUEST_URI="; echo $_SERVER['REQUEST_URI']; echo "<br />";
if(isset($_GET['action-joueur']))
{echo "action-joueur="; echo $_GET['action-joueur']; echo "<br />";}
}

// writelogs() [WORKS]

function writelogs() 
{
$logs = 'logs-2048.txt'; 
if (isset ($_GET['action-joueur']))
{$mesg = $_GET['action-joueur'];
file_put_contents($logs, " $mesg ", FILE_APPEND);} 
}

// affiche_logs() [AFFICHE TOUTES LES LIGNES, A MODIFIER]

function affiche_logs()
{
$nb1 = 5;
$affichelogs = file("logs-2048.txt");
$sizelogs = sizeof ($affichelogs);
for ($i=0; $i < $nb1; $i++)
{
if (isset($affichelogs [$i]))
{echo $affichelogs [$i];}
}
}

/* --------------------
		
fichier_vers_matrice() / matrice_vers_fichier() [WORKS]

--------------------- */

function update_fichier_vers_matrice()
{
	global $grille;
	$chaine = file_get_contents('grille.txt');
	$chaine = str_replace("\n", " ", $chaine);
	$valeurs = explode(' ', $chaine);
	$n = 0;
	for ($i = 0; $i < 4 ; $i++)
	{
		for ($j = 0; $j < 4; $j++) 
		{
			$grille[$i][$j] = (int) ($valeurs[$n]);
			$n++;
	    }
    }
}

function update_matrice_vers_fichier()
{
	global $grille;
	$nbElement = 1;
    for ($ligne=0; $ligne<4; $ligne++) 
    {
		for ($colonne=0; $colonne<4; $colonne++) 
        {
			if ( ($nbElement % 4) != 0 )
            { 
				file_put_contents('grille.txt', $grille[$ligne][$colonne], FILE_APPEND);
				file_put_contents('grille.txt', " ", FILE_APPEND);
			}
			else 
            {
				file_put_contents('grille.txt', $grille[$ligne][$colonne], FILE_APPEND);
				file_put_contents('grille.txt', "\n", FILE_APPEND);
			}
			$nbElement++;
		}
	}
}

function update_matrice_vers_fichier_blank()
{
	file_put_contents('grille.txt', "");
}

/* --------------------

nouvelle_partie()

--------------------- */

function nouvelle_partie()
{
global $score;
global $grille;

$score = 0;
file_put_contents('score.txt', $score);

$grille = array_fill(0,4,array_fill(0,4,0));

$tab = tirage_position_vide();
$i = $tab[0];
$j = $tab[1];
$grille[$i][$j] = 2;
$tab = tirage_position_vide();
$i = $tab[0];
$j = $tab[1];
$grille[$i][$j] = 2;
}

/* ------------------------------

Tirages aléatoires des nombres et des coordonnées dans la grille, partie perdue

------------------------------ */

function tirage_position_vide()
{
	global $grille;
	
	if(grille_pleine() == false)
	{
		$tab_tirage_position_vide = array(2);
		
	    $tab_tirage_position_vide_i = rand(0, 3);
	    $tab_tirage_position_vide_j = rand(0, 3);
		
	    while($grille[$tab_tirage_position_vide_i][$tab_tirage_position_vide_j] != 0)
	    {
		    $tab_tirage_position_vide_i = rand(0, 3);
		    $tab_tirage_position_vide_j = rand(0, 3);
	    }
	    
	    $tab_tirage_position_vide[0] = $tab_tirage_position_vide_i;
	    $tab_tirage_position_vide[1] = $tab_tirage_position_vide_j;
	    return $tab_tirage_position_vide;
    }
}

function grille_pleine()
{
	global $grille;
	for($i=0; $i<4; $i++)
	{
		for($j=0; $j<4; $j++)
		{
			if($grille[$i][$j] != 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

function tirage_2ou4()
{
	return rand(1, 2) * 2;
}

function  place_nouveau_nb()
{
	global $grille;
	
	$tab_place_nouveau_nb = array(2);
	$tab_place_nouveau_nb = tirage_position_vide();

	$tab_place_nouveau_nb_i = $tab_place_nouveau_nb[0];
	$tab_place_nouveau_nb_j = $tab_place_nouveau_nb[1];
	
	$grille[$tab_place_nouveau_nb_i][$tab_place_nouveau_nb_j] = tirage_2ou4();
}

/* ------------------------------

Décalage de toutes les cellules dans la direction souhaitée par le joueur

------------------------------ */

function decale_ligne_gauche($l)
{
global $grille;
$ligne = array_fill(0,4,0);
$i = 0;
for ($j = 0; $j < 4; $j++)
{
	if ($grille[$l][$j] != 0)
	{
		$ligne[$i] = $grille[$l][$j];
		$i++;
	}
}
$grille[$l] = $ligne;
}

function decale_ligne_droite($l)
{
global $grille;
$ligne = array_fill(0,4,0);
$i = 0;
for ($j = 0; $j < 4; $j++)
{
	if ($grille[$l][3 - $j] != 0)
	{
		$ligne[3 - $i] = $grille[$l][3 - $j];
		$i++;
	}
}
$grille[$l] = $ligne;
}

function decale_col_haut($c)
{
global $grille;
$colonne = array_fill(0,4,0);
$i = 0;
for ($j = 0; $j < 4; $j++)
{
	if ($grille[$j][$c] != 0)
	{
		$colonne[$i] = $grille[$j][$c];
		$i++;
	}
}
for($k = 0; $k < 4; $k++)
{
	$grille[$k][$c] = $colonne[$k];
}
}

function decale_col_bas($c)
{
global $grille;
$colonne = array_fill(0,4,0);
$i = 0;
for ($j = 0; $j < 4; $j++)
{
	if ($grille[3 - $j][$c] != 0)
	{
		$colonne[3 - $i] = $grille[3 - $j][$c];
		$i++;
	}
}
for($k = 0; $k < 4; $k++)
{
	$grille[3 - $k][$c] = $colonne[3 - $k];
}
}

/* ------------------------------

Sommation/fusion des cases de la grille

------------------------------ */
	
function fusion_ligne_gauche($l)
{
global $grille;
global $score;
$score = file_get_contents('score.txt');


if ($grille[$l][0] == $grille[$l][1])
{
	$grille[$l][0] = 2 * $grille[$l][0];
	$grille[$l][1] = 0;
	$score = $score + $grille[$l][0];
	file_put_contents('score.txt', $score);
	if ($grille[$l][2] == $grille[$l][3])
	{
		$grille[$l][2] = 2 * $grille[$l][2];
		$grille[$l][3] = 0;	
		$score = $score + $grille[$l][2];
		file_put_contents('score.txt', $score);
	}		
}
else if ($grille[$l][1] == $grille[$l][2])
{
	$grille[$l][1] = 2 * $grille[$l][1];
	$grille[$l][2] = 0;
	$score = $score + $grille[$l][1];
	file_put_contents('score.txt', $score);
}	
else if ($grille[$l][2] == $grille[$l][3])
{
	$grille[$l][2] = 2 * $grille[$l][2];
	$grille[$l][3] = 0;
	$score = $score + $grille[$l][2];
	file_put_contents('score.txt', $score);
}
}

function fusion_ligne_droite($l)
{
global $grille;
global $score;
$score = file_get_contents('score.txt');

if ($grille[$l][3] == $grille[$l][2])
{
	$grille[$l][3] = 2 * $grille[$l][3];
	$grille[$l][2] = 0;
	$score = $score + $grille[$l][3];
	file_put_contents('score.txt', $score);
	if ($grille[$l][1] == $grille[$l][0])
	{
		$grille[$l][1] = 2 * $grille[$l][1];
		$grille[$l][0] = 0;	
		$score = $score + $grille[$l][1];
	file_put_contents('score.txt', $score);	
	}		
}
else if ($grille[$l][2] == $grille[$l][1])
{
	$grille[$l][2] = 2 * $grille[$l][2];
	$grille[$l][1] = 0;
	$score = $score + $grille[$l][2];
	file_put_contents('score.txt', $score);
}	
else if ($grille[$l][1] == $grille[$l][0])
{
	$grille[$l][1] = 2 * $grille[$l][2];
	$grille[$l][0] = 0;
	$score = $score + $grille[$l][2];
	file_put_contents('score.txt', $score);
}
}

function fusion_col_haut($c)
{
global $grille;
global $score;
$score = file_get_contents('score.txt');

if ($grille[0][$c] == $grille[1][$c])
{
	$grille[0][$c] = 2 * $grille[0][$c];
	$grille[1][$c] = 0;
	$score = $score + $grille[0][$c];
	file_put_contents('score.txt', $score);
	if ($grille[2][$c] == $grille[3][$c])
	{
		$grille[2][$c] = 2 * $grille[2][$c];
		$grille[3][$c] = 0;	
		$score = $score + $grille[2][$c];
	file_put_contents('score.txt', $score);	
	}		
}
else if ($grille[1][$c] == $grille[2][$c])
{
	$grille[1][$c] = 2 * $grille[1][$c];
	$grille[2][$c] = 0;
	$score = $score + $grille[1][$c];
	file_put_contents('score.txt', $score);
}	
else if ($grille[2][$c] == $grille[3][$c])
{
	$grille[2][$c] = 2 * $grille[2][$c];
	$grille[3][$c] = 0;
	$score = $score + $grille[2][$c];
	file_put_contents('score.txt', $score);
}
}

function fusion_col_bas($c)
{
global $grille;
global $score;
$score = file_get_contents('score.txt');

if ($grille[3][$c] == $grille[2][$c])
{
	$grille[3][$c] = 2 * $grille[3][$c];
	$grille[2][$c] = 0;
	$score = $score + $grille[3][$c];
	file_put_contents('score.txt', $score);
	if ($grille[1][$c] == $grille[0][$c])
	{
		$grille[1][$c] = 2 * $grille[1][$c];
		$grille[0][$c] = 0;	
		$score = $score + $grille[1][$c];
	    file_put_contents('score.txt', $score);	
	}		
}
else if ($grille[2][$c] == $grille[1][$c])
{
	$grille[2][$c] = 2 * $grille[2][$c];
	$grille[1][$c] = 0;
	$score = $score + $grille[2][$c];
	file_put_contents('score.txt', $score);
}	
else if ($grille[1][$c] == $grille[0][$c])
{
	$grille[1][$c] = 2 * $grille[2][$c];
	$grille[0][$c] = 0;
	$score = $score + $grille[2][$c];
	file_put_contents('score.txt', $score);
}
}

/* ------------------------------

couleur_cellule()

------------------------------ */

function couleur_cellule()
{
global $grille;

switch ($grille[$i][$j]) 
{
	case 0:
	echo " <td class='cell'> ";
	break;
	case 2:
	echo " <td class='cell2'> ";
	break;
	case 4:
	echo "<td class='cell4'> 4 </td>";
	break;
	case 8:
	echo "<td class='cell8'> 8 </td>";
	break;
	case 16:
	echo "<td class='cell16'> 16 </td>";
	break;
	case 32:
	echo "<td class='cell32'> 32 </td>";
	break;
	case 64:
	echo "<td class='cell64'> 64 </td>";
	break;
	case 128:
	echo "<td class='cell128'> 128 </td>";
	break;
	case 256:
	echo "<td class='cell256'> 256</td>";
	break;
	case 512:
	echo "<td class='cell512'> 512 </td>";
	break;
	case 1024:
	echo "<td class='cell1024'> 1024 </td>";
	break;
	case 2048:
	echo "<td class='cell2048'> 2048 </td>";
	break;
}
}

?>
