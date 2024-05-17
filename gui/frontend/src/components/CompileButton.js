import React from 'react';

function CompileButton({ compileCode }) {
    return (
        <button onClick={compileCode}>Compile</button>
    );
}

export default CompileButton;
