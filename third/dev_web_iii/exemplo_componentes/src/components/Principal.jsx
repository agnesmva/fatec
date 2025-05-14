import Card from "./Card";
import "../styles/Principal.css"

export default function Principal() {
    return (
        <>
            <main>
                <section id="ofertas">
                    <Card
                        imagem='https://m.media-amazon.com/images/I/61mcOyUlsTL.jpg'
                        produto="Pen Drive 64 Gb"
                        preco="R$ 29,90"
                    />
                    <Card
                        imagem='https://img.kalunga.com.br/fotosdeprodutos/220204z.jpg'
                        produto="Impressora HP Deskjet"
                        preco="R$ 315,90"
                    />
                    <Card
                        imagem='https://fujiokadistribuidor.vteximg.com.br/arquivos/ids/214621'
                        produto="Notebook Lenovo"
                        preco="R$ 3380,90"
                    />
                </section>
            </main>
        </>
    );
}
