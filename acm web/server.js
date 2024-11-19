const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const cors = require('cors');

const app = express();
const PORT = 5000;

// Middleware
app.use(bodyParser.json());
app.use(cors());

// MongoDB Connection
mongoose.connect('mongodb://localhost:27017/acm_events', {
    useNewUrlParser: true,
    useUnifiedTopology: true,
}).then(() => console.log("Connected to MongoDB"))
  .catch(err => console.error("Failed to connect to MongoDB:", err));

// Schema for registration
const registrationSchema = new mongoose.Schema({
    name: String,
    email: String,
    department: String,
    year: String,
    registeredAt: { type: Date, default: Date.now },
});

const Registration = mongoose.model('Registration', registrationSchema);

// API Route to handle form submissions
app.post('/register', async (req, res) => {
    try {
        const registration = new Registration(req.body);
        await registration.save();
        res.status(201).send({ message: "Registration successful!" });
    } catch (error) {
        res.status(500).send({ error: "Failed to register. Try again later." });
    }
});

// Start server
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
