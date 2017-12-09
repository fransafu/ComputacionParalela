class CreateAsignaturas < ActiveRecord::Migration[5.0]
  def change
    create_table :asignaturas do |t|
      t.string :nombre
      t.string :codigo
      t.integer :departamento_id
      t.integer :creditos
      t.integer :horas_semanales

      t.timestamps
    end
  end
end
