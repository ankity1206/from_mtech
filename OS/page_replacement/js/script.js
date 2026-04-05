function visualize() {
    let input = document.getElementById("input_string").value;
    let framesCount = parseInt(document.getElementById("frame_size").value);
    let algo = document.getElementById("algorithm").value;

    if (!input || !framesCount || !algo) {
        alert("Fill all fields");
        return;
    }

    let pages = input.trim().split(/\s+/).map(Number);
    let frames = Array(framesCount).fill(null);

    let hits = 0, faults = 0;
    let output = "<table><tr><th>Page</th>";

    for (let i = 0; i < framesCount; i++) {
        output += `<th>Frame ${i+1}</th>`;
    }
    output += "<th>Status</th></tr>";

    let pointer = 0;
    let time = Array(framesCount).fill(-1);

    for (let i = 0; i < pages.length; i++) {
        let page = pages[i];
        let hit = frames.includes(page);
        let replacedIndex = -1;

        output += `<tr><td>${page}</td>`;

        if (hit) {
            hits++;

            if (algo === "LRU") {
                let index = frames.indexOf(page);
                time[index] = i;
            }
        } else {
            faults++;

            // FIFO
            if (algo === "FIFO") {
                if (frames.includes(null)) {
                    replacedIndex = frames.indexOf(null);
                } else {
                    replacedIndex = pointer;
                    pointer = (pointer + 1) % framesCount;
                }
                frames[replacedIndex] = page;
            }

            // OPTIMAL
            else if (algo === "Optimal") {
                if (frames.includes(null)) {
                    replacedIndex = frames.indexOf(null);
                } else {
                    let future = frames.map(f =>
                        pages.slice(i + 1).indexOf(f)
                    );

                    let idx = future.indexOf(-1);
                    if (idx === -1) {
                        idx = future.indexOf(Math.max(...future));
                    }
                    replacedIndex = idx;
                }
                frames[replacedIndex] = page;
            }

            // LRU
            else if (algo === "LRU") {
                if (frames.includes(null)) {
                    replacedIndex = frames.indexOf(null);
                } else {
                    replacedIndex = time.indexOf(Math.min(...time));
                }
                frames[replacedIndex] = page;
                time[replacedIndex] = i;
            }
        }

        frames.forEach((f, idx) => {
            let cls = (idx === replacedIndex && !hit) ? "highlight" : "";
            output += `<td class="${cls}">${f !== null ? f : "-"}</td>`;
        });

        output += `<td class="${hit ? "hit" : "miss"}">
            ${hit ? "Hit" : "Miss"}
        </td></tr>`;
    }

    output += "</table>";
    document.getElementById("output").innerHTML = output;

    let hitRate = (hits / pages.length * 100).toFixed(2);
    let missRate = (faults / pages.length * 100).toFixed(2);

    document.getElementById("summary").innerHTML = `
        <p>Page Faults: <b>${faults}</b></p>
        <p>Page Hits: <b>${hits}</b></p>
        <p>Hit Rate: <b>${hitRate}%</b></p>
        <p>Miss Rate: <b>${missRate}%</b></p>
    `;
}

function resetPage() {
    location.reload();
}
