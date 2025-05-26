
export default function ListaDinamica(props){
    return(
        <>
            <ul>
                {
                    props.opcoes.map(opcao => (
                        <li key= {opcao}>{opcao}</li>
                    ))
                }
            </ul>
        </>
    );
}