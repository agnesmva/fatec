import { useState } from 'react'
import React, { Fragment } from 'react';
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function MeuComponent(){
  return(
    <section>
      <h1>Tes</h1>
      <p>asuhs</p>
      <h1>ijasisja</h1>
    </section>
    
  )
}
function Teste2(){
  return(
    <main>
      <p>aushausa</p>
      <h1>344323</h1>
    </main>
    
  )
}

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <div> 
        
        <MeuComponent/>   
        <Teste2/>    
        <a href="https://vite.dev" target="_blank">
          <img src={viteLogo} className="logo" alt="Vite logo" />
        </a>
        <a href="https://react.dev" target="_blank">
          <img src={reactLogo} className="logo react" alt="React logo" />
        </a>
      </div>
      <h1>Vite + React</h1>
      <div className="card">
        <button onClick={() => setCount((count) => count + 2)}>
          a contagem está em {count}
        </button>
        <p>
          Edit <code>src/App.jsx</code> and save to test HMR
        </p>
      </div>
      <p className="read-the-docs">
        Click on the Vite and React logos to learn more
      </p>
    </>
  )
}

export default App
