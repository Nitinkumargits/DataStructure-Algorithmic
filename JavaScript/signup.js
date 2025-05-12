exports.signup = catchAsync(async (req, res, next) => {
  /**
      .create(pass obj with data from which user should be created),
      User.create(req.body) return a promise so we should await that 
    */
  const newUser = await User.create({
    name: req.body.name,
    email: req.body.email,
    password: req.body.password,
    passwordConfirm: req.body.passwordConfirm,
    passwordChangedAt: req.body.passwordChangedAt,
    role: req.body.role,
  });

  const url = `${req.protocol}://${req.get("host")}/me`; //http://localhost:3000/me
  // console.log(url);
  await new Email(newUser, url).sendWelcome();

  //  signin in/logged in new user */
  //   const token = jwt.sign({ id: newUser._id }, process.env.JWT_SECRET, {
  //     expiresIn: process.env.JWT_EXPIRES_IN
  //    });

  // createSendToken(newUser, 201, res);

  const token = signToken(newUser._id);

  res.status(201).json({
    status: "success",
    token,
    data: {
      user: newUser,
    },
  });
});
