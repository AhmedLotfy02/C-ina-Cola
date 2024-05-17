import os
from flask import Flask, request, jsonify, send_from_directory
from flask_cors import CORS

app = Flask(__name__)
CORS(app)
@app.route('/')
def index():
    return send_from_directory('templates', 'index.html')

@app.route('/compile', methods=['POST'])
def compile_code():
    data = request.json
    code = data.get('code')
    if not code:
        return jsonify({'error': 'No code provided'}), 400

    os.chdir('..')
    os.chdir('..')
    with open("test/temp.c", "w") as f:
        f.write(code)

    os.system('make runGui')
    # os.system('./main < ./test/temp.c > ./test/out/temp.out')

    with open('test/out/temp.out', 'r') as f:
        output = f.read()

    os.remove('test/temp.c')
    os.chdir('gui/Backend')

    return jsonify({'output': output})

if __name__ == '__main__':
    app.run(debug=True)
