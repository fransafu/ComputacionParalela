class CreateDocentes < ActiveRecord::Migration[5.0]
  def change
    create_table :docentes do |t|
      t.string :nombres
      t.string :apellidos
      t.string :rut
      t.integer :departamento_id
      t.boolean :activo
      t.string :email

      t.timestamps
    end
  end
end
