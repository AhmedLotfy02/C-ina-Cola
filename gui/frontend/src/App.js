import React, { useState } from 'react';
import CodeEditor from './components/CodeEditor'
import Output from './components/Output';
import CompileButton from './components/CompileButton';
import axios from 'axios';
import './App.css';

function App() {
    const [code, setCode] = useState('');
    const [output, setOutput] = useState('');
    const [semanticErrors, setSemanticErrors] = useState([]);
    const [syntaxErrors, setSyntaxErrors] = useState([]);
    // const [variableErrors, setVariableErrors] = useState([]);
    const [quadsLines, setQuadsLines] = useState([]);
    const [symbolTable, setSymbolTable] = useState([]);
    const [outputP, setOutputpanel] = useState([]);



    const compileCode = () => {
        //print
        console.log("Code: " + code);
        axios.post('http://localhost:5000/compile', { code })
        .then(response => {
          setOutput(response.data.output);
          filterErrors(response.data.output);
      })
        .catch(error => console.error('Error:', error));
    };
    
    const filterErrors = (output) => {
      const lines = output.split('\n');
      const filteredLines = lines.filter(line => !line.includes('Semantic Error')&& !line.includes('Print Result') && !line.startsWith('Error: ') && !line.startsWith('Error: variable') && !line.includes('Quads')&& 
      !line.startsWith('SymbolTable')
    );
      setOutput(filteredLines.join('\n'));

      filterSemanticErrors(output);
      filterSyntaxErrors(output);
      filterQuadsLines(output);
      filterSymbolTable(output);
      filterOutLines(output);

  };

  const filterSemanticErrors = (output) => {
      const lines = output.split('\n');
      const semanticErrorLines = lines.filter(line => line.includes('Semantic Error'));
      setSemanticErrors(semanticErrorLines);
  };
  const filterSymbolTable = (output) => {
    const lines = output.split('\n');
    const symbolTableLines = lines.filter(line => line.includes('SymbolTable'));
    setSymbolTable(symbolTableLines);
};
  const filterSyntaxErrors = (output) => {
      const lines = output.split('\n');
      const syntaxErrorLines = lines.filter(line => line.startsWith('Syntax'));
      setSyntaxErrors(syntaxErrorLines);
  };
  const filterQuadsLines = (output) => {
    const lines = output.split('\n');
    const quadsLines = lines.filter(line => line.includes('Quads'));
    setQuadsLines(quadsLines);
};
const filterOutLines = (output) => {
  const lines = output.split('\n');
  const filteredLines = lines.filter(line => line.includes('Print Result'));


  setOutputpanel(filteredLines);
};

return (
  <div className="App">
  <a href="https://imgbb.com/"><img src="https://i.ibb.co/BNnLVXn/image-removebg-preview-4.png" alt="image-removebg-preview-4" border="0" className='background-image'/></a>
      <h1>C-ina Cola Compiler</h1>
      <div className="panels-container">
          <div className="panel">
              <h2>Source Code</h2>
              <CodeEditor code={code} setCode={setCode} />
          </div>
          <div className='panel'>
          <CompileButton compileCode={compileCode} />
          </div>
          <div className="panel">
              <h2>Semantic Errors</h2>
              <pre>
                  {semanticErrors.map((error, index) => (
                      <li key={index}>{error}</li>
                  ))}
              </pre>
          </div>
          <div className="panel">
              <h2>Output</h2>
              <pre>
                  {outputP.map((error, index) => (
                      <li key={index}>{error}</li>
                  ))}
              </pre>
          </div>
          
          <div className="panel">
              <h2>Syntax Errors</h2>
              <pre>
                  {syntaxErrors.map((error, index) => (
                      <li key={index}>{error}</li>
                  ))}
              </pre>
          </div>
          <div className="panel">
              <h2>Quadruples</h2>
              <pre>
                  {quadsLines.map((line, index) => (
                      <li key={index} className={line.includes('Quads') ? 'highlightQuads' : ''}>{line}</li>
                  ))}
              </pre>
          </div>
          <div className="panel">
              <h2>Symbol Table</h2>
              <pre>
                  {symbolTable.map((line, index) => (
                      <li key={index}>{line}</li>
                  ))}
              </pre>
          </div>
          <div className="panel">
              
              <Output output={output} />
          </div>
          
      </div>
  </div>
);

}

export default App;
