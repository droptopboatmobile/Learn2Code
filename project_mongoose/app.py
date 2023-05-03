from flask import Flask, jsonify, request

app = Flask(__name__)

# Initialize the hit counter
hit_counter = 0

# Define the route for the hit counter API
@app.route('/api/hits', methods=['POST'])
def increment_hit_counter():
    global hit_counter
    hit_counter += 1
    return jsonify({'hitCount': hit_counter})

@app.route('/')
def hello_world():
    return 'Hello, World!'

if __name__ == '__main__':
    app.run(debug=True)