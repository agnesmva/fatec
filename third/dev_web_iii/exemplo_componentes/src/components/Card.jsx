import "../styles/Card.css"
import BotaoCurtidor from "./BotaoCurtidor";

export default function Card(props) {
    return (
        <div className="card">
            <img src={ props.imagem} />
            <h3>{ props.produto }</h3>
            <span>{ props.preco }</span>
            <BotaoCurtidor />
        </div>
        
    );
}
