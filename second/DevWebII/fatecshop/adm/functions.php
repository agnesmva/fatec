<?php 
function adm_validate($username, $password){
    if($username == "admin" && $password == "0101"){
        return true;
    }
    return false;
}
?>