console.log("Start");

setTimeout(() => {
  console.log("1st task after 1 second");

  setTimeout(() => {
    console.log("2nd task after 2 seconds");

    setTimeout(() => {
      console.log("3rd task after 3 seconds");

      setTimeout(() => {
        console.log("4th task after 4 seconds");
      }, 5000);
    }, 4000);
  }, 2000);
}, 3000);
