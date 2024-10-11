* oop - ex2
* exercise to practice the use of C++ templates
=========================

-------------------------
*Yehu Raccah
-------------------------

* console app for filling a 101 form.

* list of files:
	-Address pattern.h/.cpp - defines an address pattern
	-BaseField.h/.cpp - defines a base class for form fields
	-BaseFormValidator.h/cpp - defines a base class for form specific validators
	-Date.h/.cpp - defines an object to represent dates as integers
	-Field.h - derived from base field, template class for different fields
	-Form.h/.cpp - main class, holds fields and form validators.
	-IdValidator.h/.cpp - class to validate a uint32_t as an ID
	-IncomeOptions.h/.cpp - defines available income options
	-IncomesAndOtherIncomesValidator.h/.cpp - derived from FormValidator, a class for form specific validation
	-MailPattern.h/.cpp - defines an Email pattern
	-NamePattern.h/.cpp - defines a Name Pattern
	-Options.h/.cpp - base class for income and tax options
	-OtherIncomes.h/.cpp - defines available other income options
	-OtherIncomesAndTaxCreditsValidator.h/.cpp - derived from FormValidator, a class for form specific validation
	-RangeValidator.h - derived from Validator, class to validate item in a specific range
	-RegexValidator.h/.cpp - derived from Validator, class to validate if a string matches a regex pattern
	-TaxCredits.h/.cpp - defines available tax credit options
	-Validator.h - template abstract base class for field validators
	-ValuesToNames.h - template class that holds to represent choices of any options type

* data structures:
	-vector of BaseField*, used polymorphically to hold different types of Fields in the main form
	-vector of BaseFormValidator*, used polymorphically to have different type of form specific validators

* algorithms:
	
* design:
	-Validator - base class for all Field Validators
		-RangeValidator - derived class for Validator validate if items in a given range
		-IdValidator , Regex Validator - derived class for Validator will validate types uint32_t and strings

	-BaseFormValidator - abstract base class for Form Validators
		-IncomesAndOtherIncomesValidator , OtherIncomesAndTaxCreditsValidator - validate the sections of form based on given logic
	
	-Options - base class for available options to fill in sections 7,8,9 in form
		-IncomeOptions, OtherIncomes, TaxCredits - derived from Options, define allowed values and its names

	-BaseField - template base class for all types of Fields
		-Field - derived template class from Base fields, holds the appropriate validator, value and error msg

	-Form - holds all Field polymorphically as BaseField* vector
		  - holds necessary form specific validator in BaseFormValidator* vector
		  - the main interface to filling printing and validating the form
	
* known issues:

* notes:
