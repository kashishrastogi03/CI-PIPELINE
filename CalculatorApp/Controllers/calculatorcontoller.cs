using Microsoft.AspNetCore.Mvc;

public class CalculatorController : Controller
{
    [HttpGet]
    public IActionResult Index()
    {
        return View();
    }

    [HttpPost]
    public IActionResult Calculate(double num1, double num2, string operation)
    {
        double result = 0;

        switch (operation)
        {
            case "add":
                result = num1 + num2;
                break;
            case "subtract":
                result = num1 - num2;
                break;
            case "multiply":
                result = num1 * num2;
                break;
            case "divide":
                result = num2 != 0 ? num1 / num2 : double.NaN;
                break;
        }

        ViewBag.Result = result;
        return View("Index");
    }
}
