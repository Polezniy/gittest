using System.Collections;
using System.Collections.Generic;
using UnityEngine;

class GameObject2D 
{
	string name; 

	public void setName(string n)
	{
		
	}

	public string getName()
	{
		return name;
	}
}

class Rectangle : GameObject2D 
{
	private int width;
	private int height;

	public Rectangle(string name, int width, int height)
	{

	}
}

public class CSharpDemo : MonoBehaviour {

	// Use this for initialization
	void Start () {
		value_DataType ();
		reference_DataType ();
		createGameObject2D ();


	}
	
	// Update is called once per frame
	void Update () {

	}

	void value_DataType()
	{
		//transform position gives the position of the sphere
		Debug.Log ("x = " + transform.position.x + " y =" + transform.position.y + " z =" + transform.position.z);

		Vector3 v1 = transform.position;
		v1.x += 1f; v1.y += 1f; v1.z = +1f;

		Debug.Log ("x = " + transform.position.x + " y =" + transform.position.y + " z=" + transform.position.z);
	}

	void reference_DataType()
	{
		//transform.position gives the position of the sphere
		Debug.Log ("x = " + transform.position.x + " y=" + transform.position.y + " z=" + transform.position.z);

		Transform trans = transform;

		trans.position = trans.position + new Vector3 (1f, 1f, 1f);

		Debug.Log ("x = " + transform.position.x + " y=" + transform.position.y + " z=" + transform.position.z);
	}

	void createGameObject2D ()
	{
		GameObject2D Peter = new GameObject2D();

		string p = "Peter";
		string d = "David";
		string j = "John";

		List<string> namesList = new List<string> ();
		namesList.Add (p);
		namesList.Add (d);
		namesList.Add (j);

		foreach (string s in namesList)
			Debug.Log (s);
	}

	void createRectangle()
	{

	}
}
