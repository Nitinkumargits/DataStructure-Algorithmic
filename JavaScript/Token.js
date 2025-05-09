const signToken = (id) => {
  return jwt.sign({ id: id }, process.env.JWT_SECRET, {
    expiresIn: process.env.JWT_EXPIRES_IN,
  });
};

const createSendToken = (user, statusCode, req, res) => {
  const token = signToken(user._id);
  const cookieOptions = {
    expires: new Date(
      Date.now() + process.env.JWT_COOKIE_EXPIRES_IN * 24 * 60 * 60 * 1000
    ),
    // secure: true, // cookie will only be sent on an encrypted connection(https)
    httpOnly: true, // cookie can't be modified by the browser
  };
  cookieOptions.secure =
    req.secure || req.headers["x-forwarded-proto"] === "https";

  res.cookie("jwt", token, cookieOptions);

  // Removes the password from output
  // eslint-disable-next-line no-param-reassign
  user.password = undefined;

  res.status(statusCode).json({
    status: "success",
    token: token,
    data: {
      user: user,
    },
  });
};
