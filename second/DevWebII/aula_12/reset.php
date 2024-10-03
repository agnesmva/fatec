<?php
    session_start();
    $_SESSION['contador'] = 0;
    header('Location: http://localhost:3030/contador.php');
?>