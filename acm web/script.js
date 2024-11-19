document.getElementById("registrationForm").addEventListener("submit", async function(event) {
    event.preventDefault();

    const name = document.getElementById("name").value.trim();
    const email = document.getElementById("email").value.trim();
    const department = document.getElementById("department").value.trim();
    const year = document.getElementById("year").value;

    if (!name || !email || !department || !year) {
        alert("Please fill out all fields.");
        return;
    }

    try {
        const response = await fetch('http://localhost:5000/register', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ name, email, department, year }),
        });

        const data = await response.json();

        if (response.ok) {
            alert(data.message);
            document.getElementById("registrationForm").reset();
        } else {
            alert(data.error || "Failed to register. Try again later.");
        }
    } catch (error) {
        console.error("Error:", error);
        alert("Server error. Please try again later.");
    }
});
