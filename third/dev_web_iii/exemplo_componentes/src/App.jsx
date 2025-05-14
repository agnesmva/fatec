import './App.css'
import Cabecalho from './components/Cabecalho.jsx';
import Principal from './components/Principal.jsx';
import Rodape from './components/Rodape.jsx';

function Pagina() {
  return (
    <>
      <Cabecalho />
      <Principal />
      <Rodape />
    </>
  )
}

function App() {
  return <Pagina />;
}

export default App
