document.addEventListener('DOMContentLoaded', function () {
    // Variável para controlar o turno (X começa)
    let jogadoratual = "X";

    // Adiciona o evento de dragstart aos elementos X e O
    const oxImages = document.querySelectorAll('.ox img');
    oxImages.forEach(function(image) {
        image.addEventListener('dragstart', function(event) {
            event.dataTransfer.setData('text', event.target.alt);
        });
    });

    // Adiciona o evento de dragover aos quadrados do tabuleiro
    const tabuleiroCells = document.querySelectorAll('.tabuleiro td');
    tabuleiroCells.forEach(function(cell) {
        cell.addEventListener('dragover', function(event) {
            event.preventDefault();
        });

        // Adiciona o evento de drop aos quadrados do tabuleiro
        cell.addEventListener('drop', function(event) {
            event.preventDefault();
            const data = event.dataTransfer.getData('text');
            if (this.textContent === "") {
                this.textContent = data;
                // Verifica se houve um vencedor após cada movimento
                if (checkWinner()) {
                    document.getElementById('ganhou').textContent = "O jogador " + jogadoratual + " venceu!";
                    resetGame();
                } else {
                    // Alterna o turno
                    jogadoratual = jogadoratual === "X" ? "O" : "X"; //usar ternário para selecionar
                    document.querySelector('h2').textContent = "É a vez do jogador " + jogadoratual;
                }
            }
        });
    });

    // Função para verificar se há um vencedor
    function checkWinner() {
        const board = [];
        tabuleiroCells.forEach(function(cell) {
            board.push(cell.textContent);
        });
        const winningCombos = [
            [0, 1, 2],
            [3, 4, 5],
            [6, 7, 8],
            [0, 3, 6],
            [1, 4, 7],
            [2, 5, 8],
            [0, 4, 8],
            [2, 4, 6]
        ];
        for (let combo of winningCombos) {
            if (board[combo[0]] !== "" && board[combo[0]] === board[combo[1]] && board[combo[0]] === board[combo[2]]) {
                return true;
            }
        }
        return false;
    }

    // Função para reiniciar o jogo
    function resetGame() {
        tabuleiroCells.forEach(function(cell) {
            cell.textContent = "";
        });
        jogadoratual = "X";
        document.querySelector('h2').textContent = "Arraste para começar";
    }
});