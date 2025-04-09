class DisjointSet {
  constructor(n) {
    this.parent = Array(n).fill(-1);
    this.size = Array(n).fill(1);
  }

  find(u) {
    if (this.parent[u] === -1) return u;
    return (this.parent[u] = this.find(this.parent[u])); // Path compression
  }

  union(u, v) {
    let pu = this.find(u);
    let pv = this.find(v);
    if (pu === pv) return;

    if (this.size[pu] < this.size[pv]) {
      this.parent[pu] = pv;
      this.size[pv] += this.size[pu];
    } else {
      this.parent[pv] = pu;
      this.size[pu] += this.size[pv];
    }
  }

  hasCycle(edges) {
    for (let [u, v] of edges) {
      if (this.find(u) === this.find(v)) return true;
      this.union(u, v);
    }
    return false;
  }

  printParents() {
    console.log("Parent Array:");
    this.parent.forEach((p, i) => {
      console.log(`Node ${i} -> Parent: ${p}`);
    });
  }
}

// Example usage
let n = 6;
let edges = [
  [0, 1],
  [1, 2],
  [2, 3],
  [3, 4],
  [4, 5],
  [5, 0],
];

let ds = new DisjointSet(n);

if (ds.hasCycle(edges)) console.log("Cycle Detected");
else console.log("No Cycle");

ds.printParents();
