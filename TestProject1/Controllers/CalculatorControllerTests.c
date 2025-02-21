using Xunit;
using Microsoft.AspNetCore.Mvc;
using CalculatorApp.Controllers;

public class CalculatorControllerTests
{
    private readonly CalculatorController _controller;

    public CalculatorControllerTests()
    {
        _controller = new CalculatorController();
    }

    [Fact]
    public void Add_TwoNumbers_ReturnsCorrectResult()
    {
        // Act
        var result = _controller.Calculate(5, 3, "add") as ViewResult;

        // Assert
        Assert.NotNull(result);
        Assert.Equal(8.0, result.ViewData["Result"]);
    }

    [Fact]
    public void Subtract_TwoNumbers_ReturnsCorrectResult()
    {
        // Act
        var result = _controller.Calculate(10, 4, "subtract") as ViewResult;

        // Assert
        Assert.NotNull(result);
        Assert.Equal(6.0, result.ViewData["Result"]);
    }

    [Fact]
    public void Multiply_TwoNumbers_ReturnsCorrectResult()
    {
        // Act
        var result = _controller.Calculate(6, 7, "multiply") as ViewResult;

        // Assert
        Assert.NotNull(result);
        Assert.Equal(42.0, result.ViewData["Result"]);
    }

    [Fact]
    public void Divide_ByNonZero_ReturnsCorrectResult()
    {
        // Act
        var result = _controller.Calculate(10, 2, "divide") as ViewResult;

        // Assert
        Assert.NotNull(result);
        Assert.Equal(5.0, result.ViewData["Result"]);
    }

    [Fact]
    public void Divide_ByZero_ReturnsNaN()
    {
        // Act
        var result = _controller.Calculate(5, 0, "divide") as ViewResult;

        // Assert
        Assert.NotNull(result);
        Assert.Equal(double.NaN, result.ViewData["Result"]);
    }

    [Fact]
    public void UnsupportedOperation_ReturnsDefaultOrError()
    {
        // Act: Using an unsupported operation "modulus"
        var result = _controller.Calculate(5, 3, "modulus") as ViewResult;

        // Assert: Adjust this expectation based on how you wish to handle unsupported operations.
        // For instance, if your controller returns 0.0 for unsupported operations:
        Assert.NotNull(result);
        Assert.Equal(0.0, result.ViewData["Result"]);
    }

    [Fact]
    public void Add_NegativeNumbers_ReturnsCorrectResult()
    {
        // Act
        var result = _controller.Calculate(-5, -3, "add") as ViewResult;

        // Assert
        Assert.NotNull(result);
        Assert.Equal(-8.0, result.ViewData["Result"]);
    }

    [Fact]
    public void Multiply_WithDecimalNumbers_ReturnsCorrectResult()
    {
        // Act
        var result = _controller.Calculate(2.5, 4, "multiply") as ViewResult;

        // Assert
        Assert.NotNull(result);
        Assert.Equal(10.0, result.ViewData["Result"]);
    }
}
