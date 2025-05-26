import '../styles/Rodape.css'
import ListaDinamica from './ListaDinamica';

export default function Rodape() {
    return (
        <>
            <footer>
                <ListaDinamica opcoes={ ["Instagram", "Twitter", "Tiktok", "BlueSky"] } />
                <address>
                    <div>
                        <p>Rua Castro Alves, 62</p>
                    </div>
                    <div>
                        <p>&copy; 2024. Todos os direitos reservados</p>
                    </div>
                    <div>
                        <p>Contato: <a href="mailto:carlos.furlan01@fatec.sp.gov.br">carlos.furlan01@fatec.sp.gov.br</a></p>
                    </div>
                </address>
            </footer>
        </>
    );
}
