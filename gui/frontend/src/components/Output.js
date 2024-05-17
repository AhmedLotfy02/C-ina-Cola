import React from 'react';

function Output({ output }) {
    return (
        <div>
            <h2>Compilation Output</h2>
            <pre>{output}</pre>
        </div>
    );
}

export default Output;
