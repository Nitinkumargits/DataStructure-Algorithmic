import React, { useEffect, useState } from "react";

function UserList() {
  const [users, setUsers] = useState([]);
  const [error, setError] = useState(null);

  useEffect(() => {
    const controller = new AbortController(); // for cancellation
    const signal = controller.signal;

    const fetchUsers = async () => {
      try {
        const response = await fetch(
          "https://jsonplaceholder.typicode.com/users",
          { signal }
        );
        if (!response.ok) throw new Error("Fetch failed");
        const data = await response.json();
        setUsers(data);
      } catch (err) {
        if (err.name === "AbortError") {
          console.log("Fetch aborted");
        } else {
          setError(err.message);
        }
      }
    };

    fetchUsers();

    // Cleanup function to abort fetch if component unmounts
    return () => {
      controller.abort();
    };
  }, []); // empty dependency array = run on mount only

  return (
    <div>
      <h2>User List</h2>
      {error && <p style={{ color: "red" }}>{error}</p>}
      <ul>
        {users.map((user) => (
          <li key={user.id}>{user.name}</li>
        ))}
      </ul>
    </div>
  );
}
