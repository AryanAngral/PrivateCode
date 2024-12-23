document.getElementById("addSubject").addEventListener("click", addSubject);

function addSubject() {
    const subjectDiv = document.createElement("div");
    subjectDiv.classList.add("subject");
    
    const subjectNameInput = document.createElement("input");
    subjectNameInput.classList.add("subject-name");
    subjectNameInput.type = "text";
    subjectNameInput.placeholder = "Subject Name/Code";
    subjectNameInput.required = true;
    
    const totalClassesInput = document.createElement("input");
    totalClassesInput.classList.add("total-classes");
    totalClassesInput.type = "number";
    totalClassesInput.placeholder = "Total Classes";
    totalClassesInput.required = true;
    
    const attendedClassesInput = document.createElement("input");
    attendedClassesInput.classList.add("attended-classes");
    attendedClassesInput.type = "number";
    attendedClassesInput.placeholder = "Classes Attended";
    attendedClassesInput.required = true;
    
    const removeButton = document.createElement("button");
    removeButton.type = "button";
    removeButton.textContent = "Remove Subject";
    removeButton.classList.add("remove-subject");
    removeButton.addEventListener("click", function() {
        subjectDiv.remove();  // Removes the subject div from the DOM
    });

    subjectDiv.appendChild(subjectNameInput);
    subjectDiv.appendChild(totalClassesInput);
    subjectDiv.appendChild(attendedClassesInput);
    subjectDiv.appendChild(removeButton);
    
    document.getElementById("subjects").appendChild(subjectDiv);
}

document.getElementById("attendanceForm").addEventListener("submit", function(event) {
    event.preventDefault();
    const name = document.getElementById("name").value;
    const subjects = document.querySelectorAll(".subject");
    
    let totalClasses = 0;
    let totalAttended = 0;
    let subjectResultsHtml = '';
    let isBelow75 = false;
    
    subjects.forEach(subject => {
        const subjectName = subject.querySelector(".subject-name").value;
        const total = parseInt(subject.querySelector(".total-classes").value);
        const attended = parseInt(subject.querySelector(".attended-classes").value);
        
        totalClasses += total;
        totalAttended += attended;

        const attendancePercentage = (attended / total) * 100;
        
        subjectResultsHtml += `<p>${subjectName}: ${attendancePercentage.toFixed(2)}% attendance</p>`;
        
        if (attendancePercentage < 75) {
            const minClassesRequired = Math.ceil((75 * total - attended * 100) / (100 - 75));
            subjectResultsHtml += `<p>Minimum classes required to achieve 75%: ${minClassesRequired}</p>`;
            isBelow75 = true;
        }
    });
    
    const overallAttendance = (totalAttended / totalClasses) * 100;
    document.getElementById("overallAttendance").textContent = `Overall Attendance: ${overallAttendance.toFixed(2)}%`;
    
    if (overallAttendance < 75) {
        const minClassesOverall = Math.ceil((75 * totalClasses - totalAttended * 100) / (100 - 75));
        subjectResultsHtml += `<p>Minimum classes required to achieve 75% overall: ${minClassesOverall}</p>`;
    } else {
        subjectResultsHtml += `<p>Congratulations! Your attendance is already above 75%!</p>`;
    }

    document.getElementById("results").style.display = "block";
    document.getElementById("subjectResults").innerHTML = subjectResultsHtml;
});
