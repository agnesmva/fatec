<?php
foreach($_GET as $chave => $elemento){
    if(!isset($_GET["teste1"])){
         echo $_GET["teste1"] = "não";
    }
    echo $_GET[$chave];
}




?>