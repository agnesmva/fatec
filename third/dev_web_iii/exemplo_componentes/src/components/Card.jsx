import "../styles/Card.css"

export default function Card(props) {
    return (
        <div class="card">
            <img src={ props.imagem} />
            <h3>{ props.produto }</h3>
            <span>{ props.preco }</span>
        </div>
    );
}
