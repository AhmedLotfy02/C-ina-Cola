import React from 'react';

function CodeEditor({ code, setCode }) {
    return (
        <textarea
            value={code}
            onChange={(e) => setCode(e.target.value)}
            rows="20"
            cols="80"
            placeholder="Enter your C+- code here..."
        />
    );
}

export default CodeEditor;
